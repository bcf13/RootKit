#!/bin/bash
sudo tail -n 10000 /var/log/syslog
sudo truncate -s 0 /var/log/syslog