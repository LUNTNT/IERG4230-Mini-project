package Routes

import (
	"proj4230/Services"

	"github.com/gofiber/fiber/v2"
)

func FeedRoute(route fiber.Router) {

	route.Get("/time/:time", Services.GetAllChannelInfo)
	route.Get("/gram/:gram", Services.GetChannelInfoById)

}

func Statroute(route fiber.Router) {

	route.Get("/time/:time", Services.GetAllChannelInfo)
	route.Get("/gram/:gram", Services.GetChannelInfoById)

	route.Post("/", Services.AddChannel)

	route.Put("/id/:id", Services.UpdateChannelById)

	route.Delete("/id/:id", Services.DeleteChannelById)
}

