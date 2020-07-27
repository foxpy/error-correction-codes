package runner

import (
	"errors"
	"math/big"
	"strconv"
	"strings"
)

type Decimal struct {
	fraction *big.Int
	integral *big.Int
}

func (d *Decimal) Set(s string) error {
	splitted := strings.SplitN(s, ".", 3)
	if len(splitted) > 2 {
		return errors.New("Invalid integer format")
	}
	var fraction, integral uint64 = 0, 0
	var err error
	fraction, err = strconv.ParseUint(splitted[0], 0, 64)
	if err != nil {
		return err
	}
	if len(splitted) > 1 {
		integral, err = strconv.ParseUint(splitted[1], 0, 64)
		if err != nil {
			return err
		}
	}
	big_fraction := big.NewInt(int64(fraction))
	big_integral := big.NewInt(int64(integral))
	if integral > 0 {
		big_fraction.Mul(big_fraction, big.NewInt(int64(len(splitted[1]))))
		big_fraction.Add(big_fraction, big_integral)
		big_integral = big.NewInt(int64(len(splitted[1])))
	}
	d.fraction = big_fraction
	d.integral = big_integral
	return nil
}

func (d Decimal) String() string {
	return d.fraction.String()
}
