
#!/usr/bin/python3

import argparse
import subprocess
import os

parser = argparse.ArgumentParser()
parser.add_argument('--config', action='store_true')
parser.add_argument('--update', action='store_true')
parser.add_argument('-t', '--test', required=True)
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
    print('Updating')
    # Stage changes
    execute_cmd(['git', 'add', '.'])                                     
    # Commit changes
    execute_cmd(['git', 'commit', '-m', 'merge in new problems'])
    # Fetch updates
    execute_cmd(['git', 'fetch', 'omolazabal'])        
    # Merge in changes
    execute_cmd(['git', 'merge', '--no-edit', 'omolazabal/problems'])

def git_config():
    option = raw_input('Are you sure you want to configure Git? This will erase ALL of your progress. (y/n) ')
    option = option.lower()
    print('Configuring...')
    if option is y:
        execute_cmd(['git', 'remote', 'add', 'omolazabal', 'https://github.com/omolazabal/si-spring-2019.git'])
        execute_cmd(['git', 'fetch', 'omolazabal'])
        execute_cmd(['git', 'reset', '--hard', 'omolazabal/problems'])

if args.config:
    git_config()
elif args.update:
    update_repo()
else:
    run_test(args.test)

