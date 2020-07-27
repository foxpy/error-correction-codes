package runner

import (
	"fmt"
	"math/big"
)

func Test() {
	fmt.Println("hello world")
}

type RunnerConfig struct {
	from big.Rat
}
