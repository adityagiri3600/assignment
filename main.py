from cryptography.fernet import Fernet
import base64
import hashlib
from getpass import getpass
# pip install -q -U google-genai
from google import genai
from cryptography.fernet import InvalidToken

# pip install pymupdf
import fitz  # PyMuPDF
def pdf_to_text(pdf_path):
    pdf_document = fitz.open(pdf_path)
    
    text = ''
    for page_num in range(pdf_document.page_count):
        page = pdf_document.load_page(page_num)
        text += page.get_text()

    return text

password = getpass("password: ").encode()
key = base64.urlsafe_b64encode(hashlib.sha256(password).digest())

fernet = Fernet(key)
encrypted = b'gAAAAABn8ozVycbF1btFQESn4DHJiIFB4NFmB-44P5rj5NM9mDrwW-guKOqH3ly6tMZt1RniJNRVNfwArjAF-gJZiiPMCyt_lYiKKkaczubAKQCm_zN5ciQpAfaNbblJeKELx2vOuZlh'

try:
    api_key = fernet.decrypt(encrypted).decode()
except InvalidToken:
    print("Incorrect password")
    exit(1)

text = ''

if input("Do you want to attach a PDF? (y/N): ").strip().lower() == 'y':
    pdf_path = input("PDF path: ")
    text = pdf_to_text(pdf_path)
    contents = "Attached pdf document:\n" + "-------------PDF BEGIN-------------\n" + text + "\n-------------PDF END-------------\n" + "user prompt: " + input("q: ")
else:
    contents = input("q: ")
    
client = genai.Client(api_key=api_key)
while True:
    response = client.models.generate_content(
        model="gemini-2.0-flash", contents=contents
    )
    print(response.text)
    user_input = input("q: ")
    if user_input.lower() in ['exit', 'quit']:
        break
    contents += "\nagent: " + response.text + "\nuser: " + user_input + "\nagent: "
