import java.util.Arrays;

public class BinarySearch {
    // Function to perform binary search
    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate mid index

            // Check if target is at mid
            if (array[mid] == target) {
                return mid; // Return the index if the target is found
            }
            // If target is greater, ignore the left half
            else if (array[mid] < target) {
                left = mid + 1;
            }
            // If target is smaller, ignore the right half
            else {
                right = mid - 1;
            }
        }
        return -1; // Return -1 if the target is not found
    }

    public static void main(String[] args) {
        int[] array = {3, 5, 7, 8, 10, 12, 15};
        int target = 10;

        int result = binarySearch(array, target);

        if (result == -1) {
            System.out.println("Element not found in the array.");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }
}
