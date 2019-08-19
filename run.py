
#!/usr/bin/python3

import argparse
import subprocess
import os

parser = argparse.ArgumentParser()
parser.add_argument('--config', action='store_true')
parser.add_argument('--update', action='store_true')
parser.add_argument('-t', '--test')
args = parser.parse_args()

def has_number(string):
    return any(char.isdigit() for char in string)

def execute_cmd(cmd):
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
    for stdout_line in iter(process.stdout.readline, ''):
        yield stdout_line
    process.stdout.close()
    return_code = process.wait()
    if return_code:
        if 'make' in cmd:
            subprocess.run(['make', '-s', 'clean'])
        raise subprocess.CalledProcessError(return_code, cmd)

def run_test(unit_test):
    unit_test_paths = []
    if unit_test.lower() == 'all':
        unit_test_paths = [os.getcwd() + '/' + x for x in os.listdir(os.getcwd()) if has_number(x) ]
    else:
        unit_test_paths.append(os.getcwd() + '/' + unit_test)

    try:
        for ut in unit_test_paths:
            os.chdir(ut)
            # Compile
            for path in execute_cmd(['make', '-s', 'all']):
                print(path, end='')
            # Run
            for path in execute_cmd(['make', 'exec']):
                print(path, end='')
            # Clean
            for path in execute_cmd(['make', '-s', 'clean']):
                print(path, end='')
            os.chdir('..')
    except :
        exit(1)

def update_repo():                                                            
    print('Updating...')
    # Stage changes
    for path in execute_cmd(['git', 'add', '.']):
        print(path, end='')
    # Commit changes
    for path in execute_cmd(['git', 'commit', '-m', 'merge in new problems']):
        print(path, end='')
    # Fetch updates
    for path in execute_cmd(['git', 'fetch', 'omolazabal']):
        print(path, end='')
    # Merge in changes
    for path in execute_cmd(['git', 'merge', '--no-edit', 'omolazabal/problems']):
        print(path, end='')

def git_config():
    option = input('Are you sure you want to configure Git? This will erase ALL of your progress. (y/n) ')
    if option.lower() == 'y':
        print('Configuring...')
        for path in execute_cmd(['git', 'remote', 'add', 'omolazabal', 'https://github.com/omolazabal/si-fall-2019.git']):
            print(path, end='')
        for path in execute_cmd(['git', 'fetch', 'omolazabal']):
            print(path, end='')
        for path in execute_cmd(['git', 'reset', '--hard', 'omolazabal/problems']):
            print(path, end='')

if args.config:
    git_config()
elif args.update:
    update_repo()
elif args.test:
    run_test(args.test)
else:
    print('Invalid command')

