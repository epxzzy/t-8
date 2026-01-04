package main

import (
	"github.com/epxzzy/t-8/src/router/helper"
)

func main(){
	lagger := helper.Logger{DisableSystemProgramLogs: false};
	go helper.InitWsServer()

	go func (){
		for {
			if helper.RecieveQueue.IsEmpty() == false {
				for {
					if helper.RecieveQueue.GetLength() == 0 {
						break
					}

					lagger.Log(helper.SystemProgramLog, helper.RecieveQueue.Dequeue())
				}
			}
		}
	}()

	func (){
		for {
			inplut := helper.GetTextInput();
			//fmt.Println("LADIES AND MEN WE HAVE  " + inplut)
			//shows up late for some reason


			helper.SendToClient(inplut)
			lagger.Log(helper.ActProgramLog, "sending: " +inplut)

		}
	}()
	//spinner();

}
