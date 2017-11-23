#!/bin/bash

BINARY=$1
TESTS_DIR=$2

if [[ $# -lt 2 ]]; then
        echo "Usage: $0 prog_binary tests_dir"
        exit 1
fi

echo "-> Run positive tests"

for f in `ls $TESTS_DIR/YES`; do
        $BINARY $TESTS_DIR/YES/$f || echo "  Test $f failed!"
done

echo ""
echo "-> Run negative tests"

for f in `ls $TESTS_DIR/NO`; do
        $BINARY $TESTS_DIR/NO/$f && echo "  Test $f failed!"
done
