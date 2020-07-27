package main

import (
	"flag"
	"fmt"
	"github.com/foxpy/error-correction-codes/runner"
)

type Arguments struct {
	test *float64
}

func main() {
	args := Arguments{}
	args.test = flag.Float64("test", 0.0, "Set this for no reason")
	flag.Parse()
	fmt.Println(*args.test)
	var a runner.Decimal
	a.Set("50.1")
	fmt.Println(a)
}
