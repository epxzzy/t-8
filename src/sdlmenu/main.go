package main

import (
	"fmt"
	"math"
	"github.com/epxzzy/t-8/src/sdlmenu/helper"
	"github.com/tfriedel6/canvas"
	"github.com/tfriedel6/canvas/sdlcanvas"
	"github.com/veandco/go-sdl2/sdl"
)

var lagger = helper.Logger{DisableSystemProgramLogs: false};


func main() {
	//window
	//lagger.Log(helper.SystemProgramLog, "fuckin hell man")
	
	wnd, cv, err := sdlcanvas.CreateWindow(1024, 768, "t8-dev-aid-server")

	if err != nil {
		panic(err);
	}
	defer wnd.Destroy()	
	

	//client
	go helper.InitWsServer();

	go func (){
		for {
			//lagger.Log(helper.SystemProgramLog, "loopin it HARD")
			if helper.RecieveQueue.IsEmpty() == false {
				for {
					if helper.RecieveQueue.GetLength() == 0 {
						break
					}

					lagger.Log(helper.SystemProgramLog, "server received: " + helper.RecieveQueue.Dequeue())
				}
			}
		}
	}()


	//canvas
	state := NewAnimationState()
	mode := "NORMAL"

	//keydown event
	wnd.KeyDown = func(scancode int, rn rune, name string) {
		switch scancode {
		case sdl.SCANCODE_N:
			mode ="NORMAL"
			fmt.Println("current mode is normal")

		case sdl.SCANCODE_H:
			mode = "HYPERDRIVE"
			fmt.Println("current mode is hyperdrive")

		case sdl.SCANCODE_K:
			mode = "KEYGEN"
			fmt.Println("current mode is keygen")

		case sdl.SCANCODE_R:
			mode = "REDSHAKE"
			fmt.Println("current mode is redshake")

		case sdl.SCANCODE_G:
			mode = "GLITCHMATRIX"
			fmt.Println("current mode is glitchmatrix")

		default:
			helper.SendToClient(name)
			fmt.Println("sending over " + name)

		}
	}


	wnd.MainLoop(func() {
		w, h := float64(cv.Width()), float64(cv.Height())
		cv.SetFillStyle("#000")
		cv.FillRect(0, 0, w, h)
		//cv.FillText("T-8 Dev Aid Server", 820, 180)

		UpdateAnimation(cv, state, mode)
		cv.Restore()
		cv.SetFillStyle("#FFFFFF")
		cv.SetFont("Righteous-Regular.ttf", 40)
		str := "T-8 Dev Aid Server"
		cv.FillText(str, (w/2 - cv.MeasureText(str).Width/2), h/2)

	})

}

func UpdateAnimation(cv *canvas.Canvas, state *AnimationState, mode string) {
	width, height := cv.Size()

	//clear
	cv.SetFillStyle(0, 0, 0, 1)
	cv.FillRect(0, 0, float64(width), float64(height))

	//draw current mode
	switch mode{
	case "NORMAL":
		updateNormalMode(cv, state, width, height)
	case "HYPERDRIVE":
		updateHyperdriveMode(cv, state, width, height)
	case "KEYGEN":
		updateKeygenMode(cv, state, width, height)
	case "REDSHAKE":
		updateRedShakeMode(cv, state, width, height)
	case "GLITCHMATRIX":
		updateGlitchMatrixMode(cv, state, width, height)
	}
}

func degreesToRadians(degrees float64) float64 {
	return degrees * math.Pi / 180
}
