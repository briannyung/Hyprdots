import sys

def dec(c):
    if ord(c) >= ord('0') and ord(c) <= ord('9'):
        return ord(c) - ord('0')
    else:
        return (ord(c.upper()) - ord('A')) + 10
if(len(sys.argv) != 2):
    print("You fucked up bro.")
else:
    hex = sys.argv[1]
    r = (16 * dec(hex[2]) + dec(hex[3])) / 255
    g = (16 * dec(hex[4]) + dec(hex[5])) / 255
    b = (16 * dec(hex[6]) + dec(hex[7])) / 255
    with open("/home/Brian/.config/scripts/tints.txt", "w") as file:
        file.write(f"$walr={r}\n$walg={g}\n$walb={b}")
