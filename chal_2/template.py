from pwn import *

p = process("./vuln")
e = ELF("./vuln")

# padding
padding = 

# win function's address
# Hint: objdump -d -M intel vuln
win = 

# final payload
payload = 

# send payload!
p.sendline(payload)
p.interactive()
