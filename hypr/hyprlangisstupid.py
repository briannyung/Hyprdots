import sys

def dec(c):
    if c >= '0' && c <= '9':
        return c - '0'
    else:
        return (c - 'A') + 10
if(len(sys.argv) != 2)
    print("You fucked up bro.")
else:
    hex = sys.argv[1]
    r = (16 * dec(hex[2]) + dec(r[3])) / 255
    g = (16 * dec(hex[4]) + dec(r[5])) / 255
    b = (16 * dec(hex[6]) + dec(r[7])) / 255
    with open("~/.config/scripts/tints.txt") as file:
        file.write("$walr=" + r + "\n$walg=" + g + "\n$walb="b)
