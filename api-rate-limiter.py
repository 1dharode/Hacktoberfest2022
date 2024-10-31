from fastapi import FastAPI, HTTPException, Depends, Request
from time import time
from collections import defaultdict

app = FastAPI()

# Store request counts with timestamps
request_counts = defaultdict(list)
RATE_LIMIT = 5  # requests
RATE_LIMIT_PERIOD = 60  # seconds

async def rate_limiter(request: Request):
    client_ip = request.client.host
    current_time = time()

    # Remove timestamps older than RATE_LIMIT_PERIOD
    request_counts[client_ip] = [timestamp for timestamp in request_counts[client_ip] if timestamp > current_time - RATE_LIMIT_PERIOD]

    # Check if the rate limit is exceeded
    if len(request_counts[client_ip]) >= RATE_LIMIT:
        raise HTTPException(status_code=429, detail="Rate limit exceeded")

    # Add the current request timestamp
    request_counts[client_ip].append(current_time)

@app.get("/", dependencies=[Depends(rate_limiter)])
async def read_root():
    return {"message": "Hello, World!"}

@app.get("/items/{item_id}", dependencies=[Depends(rate_limiter)])
async def read_item(item_id: int):
    return {"item_id": item_id, "message": "Item fetched successfully"}

@app.post("/reset")
async def reset_rate_limit():
    global request_counts
    request_counts = defaultdict(list)
    return {"message": "Rate limits reset"}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000, reload=True)
