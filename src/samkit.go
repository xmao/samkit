package main

import (
	"code.google.com/p/biogo.boom"
	"fmt"
	"os"
)



func main() {
	// f, err := os.Open(os.Args[1])
	// if err != nil {
	// 	fmt.Println("open file failed")
	// 	os.Exit(1)
	// }
	
	// br, err := sam.NewReader(os.Stdin)
	br, err := boom.OpenBAM(os.Args[1])
	if err != nil {
		fmt.Println("open bam failed")
		os.Exit(1)
	}

	for r, _, e := br.Read() {
		if e != nil {
			break
		}
		fmt.Println(r.Name())
	}
}
