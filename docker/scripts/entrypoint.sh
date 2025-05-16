#!/bin/bash
set -e

udevd &
udevadm control --reload-rules
udevadm trigger

exec "$@"
