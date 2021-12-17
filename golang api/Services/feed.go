package Services

import (
	"log"
	"proj4230/DB"
	"proj4230/Model"

	"github.com/gofiber/fiber/v2"
	"go.mongodb.org/mongo-driver/bson"
)

func FeedByTime(c *fiber.Ctx) error {
	adminColl := DB.MI.FeedDBCol

	paramID := c.Params("id")

	reply := &Model.StandardReply{}
	filter := bson.D{{Key: "id", Value: paramID}}

	err := adminColl.FindOne(c.Context(), filter).Decode(reply)
	if err != nil {
		log.Println("GetReplyFolderByID FindOne ", err)
		return c.SendStatus(fiber.StatusInternalServerError)
	}

	return c.Status(fiber.StatusOK).JSON(reply)
}

func GetDeviceIP(c *fiber.Ctx) error {
	adminColl := DB.MI.FeedDBCol

	paramID := c.Params("id")

	reply := &Model.StandardReply{}
	filter := bson.D{{Key: "id", Value: paramID}}

	err := adminColl.FindOne(c.Context(), filter).Decode(reply)
	if err != nil {
		log.Println("GetReplyFolderByID FindOne ", err)
		return c.SendStatus(fiber.StatusInternalServerError)
	}

	return c.Status(fiber.StatusOK).JSON(reply)
}