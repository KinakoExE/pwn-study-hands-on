from pwn import *

p = process("./vuln")
e = ELF("./vuln")

# padding
padding = 

# win function's address
# Hint: objdump -d -M intel vuln
win = 

# pop rdi's address
# Hint: ropgadget --binary vuln
pop_rdi = 

# final payload
# Hint: padding + pop_rdi + 1st argument + function address
payload = 

# send payload!
p.sendline(payload)
p.interactive()
