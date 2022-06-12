#! /usr/bin/env python3

def main():
    print("bool is_even_if_else(int n) {")
    for i in range(2147483647):
        print("    else if (n == " + str(i) + ")")
        if i % 2 != 0:
            print("        return false;")
        else:
            print("        return true;")
    print("}")

if __name__ == "__main__":
    main()