load harness

@test "mytests-1" {
  check '2 + 3 * (10 - 5)' '17'
}

@test "mytests-2" {
  check '10 - 20 * 3 * 20' '-1190'
}


@test "mytests-3" {
  check '100 / (10 - 5)' '20'
}

@test "mytests-4" {
  check '10000 / (20+30) / 100' '2'
}

@test "mytests-5" {
  check '2147483646 - 2 + 3' '2147483647'
}
