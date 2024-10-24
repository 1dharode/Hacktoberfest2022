import cv2
import mediapipe as mp
import pyautogui
import numpy as np
import math
import time

mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils
hands = mp_hands.Hands(min_detection_confidence=0.7, min_tracking_confidence=0.5)

screen_width, screen_height = pyautogui.size()

def calculate_distance(point1, point2):
    return math.sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)

smoothening = 4
prev_x, prev_y = 0, 0

cap = cv2.VideoCapture(0)

click_hold = False
dragging = False

while True:
    success, frame = cap.read()
    if not success:
        break

    frame = cv2.flip(frame, 1)
    h, w, _ = frame.shape

    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hands.process(frame_rgb)

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            index_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]
            thumb_tip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP]
            middle_tip = hand_landmarks.landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP]

            index_x = int(index_tip.x * w)
            index_y = int(index_tip.y * h)
            screen_x = np.interp(index_x, (0, w), (0, screen_width))
            screen_y = np.interp(index_y, (0, h), (0, screen_height))

            cur_x = prev_x + (screen_x - prev_x) / smoothening
            cur_y = prev_y + (screen_y - prev_y) / smoothening
            pyautogui.moveTo(cur_x, cur_y)
            prev_x, prev_y = cur_x, cur_y

            thumb_x, thumb_y = int(thumb_tip.x * w), int(thumb_tip.y * h)
            index_distance = calculate_distance((index_x, index_y), (thumb_x, thumb_y))

            middle_x, middle_y = int(middle_tip.x * w), int(middle_tip.y * h)
            middle_distance = calculate_distance((middle_x, middle_y), (thumb_x, thumb_y))

            if index_distance < 75:
                if not click_hold:
                    click_hold = True
                    pyautogui.mouseDown()
                dragging = True
            else:
                if click_hold:
                    click_hold = False
                    if dragging:
                        pyautogui.mouseUp()
                        dragging = False

            if middle_distance < 50:
                pyautogui.rightClick()
                time.sleep(0.3)

            mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

    cv2.imshow("Hand Tracking", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
