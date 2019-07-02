

def something_different(*args):
    print(args[0].strip() + " once again")
    return "Python calculated some stuff with '%s'" % args[0].strip()
