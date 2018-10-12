import os
def read_network_counts(interface):
    cmd = 'cat /proc/net/dev | grep {0}'.format(interface)
    with os.popen(cmd) as fd:
        output = fd.read()
        bytes_raw = output.split()[1]
	return int(bytes_raw)
#print read_network_counts('eno1')


