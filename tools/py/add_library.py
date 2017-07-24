""" tool to add folder to project with the appropriate SConscript file """
import argparse
import os
import re

def main():
    parser = argparse.ArgumentParser(description="Create new library")
    parser.add_argument("name", type=str, help="Library name")
    parser.add_argument("--libraries", nargs="*", help="List of libraries" +
                        " depended on", required=False)
    args = parser.parse_args()

    base_dir = os.path.dirname(os.path.abspath(__file__))
    directory = os.path.join(base_dir, '../../src/' + args.name)

    if not os.path.exists(directory):
        os.makedirs(directory)
    else:
        raise Exception("Directory exists")

    base_scons = os.path.join(base_dir, "LibrarySConscript")
    with open(base_scons, "r") as f:
        base_scons_string = f.read()

    scons_string = re.sub("FILE_NAME", args.name, base_scons_string)
    libraries_string = "[ ]" if not args.libraries else str(args.libraries)
    scons_string = re.sub("LIBRARIES", libraries_string, scons_string)

    sconscript_name = os.path.join(directory, "SConscript")
    with open(sconscript_name, "w") as f:
        f.write(scons_string)

if __name__ == "__main__":
    main()
