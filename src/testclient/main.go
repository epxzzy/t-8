package main

import (
	"fmt"
	"github.com/tfriedel6/canvas/sdlcanvas"
	"github.com/epxzzy/t-8/src/testclient/helper"

)
var lagger = helper.Logger{DisableSystemProgramLogs: false};

func main() {

	//window
	wnd, cv, err := sdlcanvas.CreateWindow(1024, 768, "t8-dev-aid-server")
	if err != nil {
		panic(err);
	}
	defer wnd.Destroy()	

	//client
	helper.InitWSclient()

	go func (){
		for {
			helper.Dialer()
		}
	}()



	//keydown event
  wnd.KeyDown = func(scancode int, rn rune, name string) {
		helper.SendToServer(name)
    fmt.Println("sending over " + name)
	}


	wnd.MainLoop(func() {
		w, h := float64(cv.Width()), float64(cv.Height())
		cv.SetFillStyle("#000")
		cv.FillRect(0, 0, w, h)
		cv.SetFillStyle("#FFFFFF")
		cv.SetFont("Righteous-Regular.ttf", 40)
		str := "testclient"
		cv.FillText(str, (w/2 - cv.MeasureText(str).Width/2), h/2)
		cv.Restore()


	})
}

