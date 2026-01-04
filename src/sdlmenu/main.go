package main

import (
	"fmt"
	"math"

	"github.com/tfriedel6/canvas"
	"github.com/tfriedel6/canvas/sdlcanvas"
	"github.com/veandco/go-sdl2/sdl"
)

func main() {

	//window
	wnd, cv, err := sdlcanvas.CreateWindow(1024, 768, "t8-dev-aid-server")
	if err != nil {
		panic(err);
	}
	defer wnd.Destroy()	

	//client
	go initWsClient();

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
				SendToServer(name)
      	fmt.Println("sending over " + name)

    }

		HandlePossibleQueueInterrupt()
	}


	wnd.MainLoop(func() {
		w, h := float64(cv.Width()), float64(cv.Height())
		cv.SetFillStyle("#000")
		cv.FillRect(0, 0, w, h)

		UpdateAnimation(cv, state, mode )
	})
}

func HandlePossibleQueueInterrupt(){
	if RecieveQueueC.IsEmpty() == false {
		for {
			if RecieveQueueC.GetLength() == 0 {break}

			println("Recieved this from the server: "+RecieveQueueC.Dequeue())
		}
	}
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

	HandlePossibleQueueInterrupt()
}

func degreesToRadians(degrees float64) float64 {
	return degrees * math.Pi / 180
}
