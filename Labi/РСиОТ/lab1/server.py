from fastapi import FastAPI, File, UploadFile, Form, HTTPException
from fastapi.responses import RedirectResponse, FileResponse
from pydantic import BaseModel
from fastapi.responses import JSONResponse
import random
import os
import shutil
from os import listdir
from os.path import isfile, join
    
print("creating FastAPI app")
app = FastAPI(
    title="bug_tracker", 
    version="lab1", 
    description="server_description"
)

@app.get("/")
async def redirect_root_to_docs():
    return RedirectResponse("/docs")

@app.get("/connection/ping")
def pong():
    return {"message":"pong"}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
