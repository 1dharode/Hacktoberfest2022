from fastapi.testclient import TestClient
from node import app  # replace 'node' with your script name
import time

client = TestClient(app)

def reset_request_counts():
    response = client.post("/reset")
    print(f"Reset response status: {response.status_code}, response: {response.json()}")
    assert response.status_code == 200
    assert response.json() == {"message": "Rate limits reset"}

def test_read_root():
    response = client.get("/")
    print(f"Root endpoint response status: {response.status_code}, response: {response.json()}")
    assert response.status_code == 200
    assert response.json() == {"message": "Hello, World!"}

def test_read_item():
    response = client.get("/items/1")
    print(f"Items endpoint response status: {response.status_code}, response: {response.json()}")
    assert response.status_code == 200
    assert response.json() == {"item_id": 1, "message": "Item fetched successfully"}

def test_rate_limiting():
    reset_request_counts()
    for i in range(5):
        response = client.get("/")
        print(f"Request {i+1} status: {response.status_code}, response: {response.json()}")
        assert response.status_code == 200
        time.sleep(0.1)  # Small delay to avoid timing issues

    response = client.get("/")
    print(f"Rate limit test status: {response.status_code}, response: {response.json()}")
    assert response.status_code == 429
    assert response.json() == {"detail": "Rate limit exceeded"}

if __name__ == "__main__":
    test_read_root()
    test_read_item()
    test_rate_limiting()
