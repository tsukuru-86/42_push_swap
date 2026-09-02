*This project has been created as part of the 42 curriculum by tkomai.*

# push_swap

## Purpose

This repository is prepared for a full-score resubmission of push_swap. It
contains strict integer parsing, an operation-efficient sorter, and the bonus
`checker` program. It does not depend on the previously missing libft
submodule, so a fresh clone builds without external repository state.

## Build and use

```sh
make
ARG="4 67 3 87 23"
./push_swap $ARG
```

Build the bonus checker and verify the generated instructions:

```sh
make bonus
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

The parser accepts multiple integers per argument, rejects empty arguments,
non-numeric tokens, duplicates, and values outside the signed 32-bit range.
Inputs of up to five values use dedicated minimal routines. Larger inputs use
coordinate compression and chunked transfers before restoring maxima from
stack B, keeping the operation count within the full-score evaluation bands.

## Resources and AI usage

- The push_swap subject and evaluation checklist
- `man 2 write`, `man 3 malloc`, and `man 3 free`

AI was used to audit the original memory and parsing bugs, redesign the sorter,
implement the checker, and generate randomized correctness and operation-count
tests. The implementation should be understood and defensible at evaluation.
