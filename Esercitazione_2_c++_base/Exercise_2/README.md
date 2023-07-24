# Password Encryption

Caesar encryption is easy to decipher because each letter of the text is shifted of the same quantity (`k`).
The Vigenère cipher is a safer method based on a series of interwoven Ceaser ciphers, which shift the text by a variable quantity dependent from an alphabetic password.

## Example 

Clear text: `ALICE I LOVE U` \
Password: `GATTO`

Procedure:
```text
A	L	I	C	E		I		L	O	V	E		U
G	A	T	T	O		G		A	T	T	O		G
G	L	B	V	S		O		L	H	O	S		A
```

## Requirements

Write a program which reads a text from a file of name **text.txt** of the following format (avoid punctuation):

```text
THIS IS A GENERIC TEXT TO BE ENCRYPTED
```
and a password written as an input argument (*command line arguments*) of the program. 

The password must be shorter than the clear text. 

The clear text and the password shall contain only uppercase letters. The encrypted text shall preserve spaces. 

The program shall encrypt/decrypt the text and print both the results on screen.
