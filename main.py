from cryptography.fernet import Fernet
import base64
import hashlib
from getpass import getpass
# pip install -q -U google-genai
from google import genai
from cryptography.fernet import InvalidToken

password = getpass("password: ").encode()
key = base64.urlsafe_b64encode(hashlib.sha256(password).digest())

fernet = Fernet(key)
encrypted = b'gAAAAABn8ozVycbF1btFQESn4DHJiIFB4NFmB-44P5rj5NM9mDrwW-guKOqH3ly6tMZt1RniJNRVNfwArjAF-gJZiiPMCyt_lYiKKkaczubAKQCm_zN5ciQpAfaNbblJeKELx2vOuZlh'

try:
    api_key = fernet.decrypt(encrypted).decode()
except InvalidToken:
    print("Incorrect password")
    exit(1)

client = genai.Client(api_key=api_key)

response = client.models.generate_content(
    model="gemini-2.0-flash", contents=input("q: ")
)
print(response.text)
