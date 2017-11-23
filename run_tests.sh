#!/bin/bash

BINARY=$1
TESTS_DIR=$2

RESULT="PASS"

if [[ $# -lt 2 ]]; then
        echo "Usage: $0 prog_binary tests_dir"
        exit 1
fi

echo "-> Run positive tests"

for f in `ls $TESTS_DIR/YES`; do
        if ! $BINARY $TESTS_DIR/YES/$f; then 
                echo "  Test $f failed!"
                RESULT="FAIL"
        fi
done

echo ""
echo "-> Run negative tests"

for f in `ls $TESTS_DIR/NO`; do
        if $BINARY $TESTS_DIR/NO/$f; then
                echo "  Test $f failed!"
                RESULT="FAIL"
        fi
done

echo ""
echo "Result: $RESULT"
