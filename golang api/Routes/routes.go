package Routes

import (
	"proj4230/Services"

	"github.com/gofiber/fiber/v2"
)

func FeedRoute(route fiber.Router) {

	route.Get("/ip", Services.GetDeviceIP)

	route.Get("/time/:time", Services.FeedByTime)
	//route.Get("/gram/:gram", Services.GetChannelInfoById)

}

func StatRoute(route fiber.Router) {

	route.Get("/time/:time", Services.GetRecordByTime)

	route.Post("/", Services.AddFeedRecord)

	//route.Put("/id/:id", Services.UpdateChannelById)

	//route.Delete("/id/:id", Services.DeleteChannelById)
}

