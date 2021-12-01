package DB

import (
	"context"
	"fmt"

	"proj4230/Util"

	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

// type DB struct {
// 	url        string
// 	name       string
// 	collection string
// 	user       string
// 	pwd        string
// }

type MongoInstance struct {
	FeedClient *mongo.Client
	FeedDBCol  *mongo.Collection

}

var MI MongoInstance

func MongoConnect() {
	feedUrl, feedDB, feedCol := Util.GoDotEnvVariable("DB_URL"), Util.GoDotEnvVariable("DB_NAME"), Util.GoDotEnvVariable("FEED_COLLECTION")


	ctx := context.Background()
	feed, err := mongo.Connect(ctx, options.Client().ApplyURI(feedUrl))
	if err != nil {
		fmt.Println("Cannot connect database")
	}
	feeds := feed.Database(feedDB).Collection(feedCol)


	fmt.Println("DB connected!")
	MI = MongoInstance{
		FeedClient: feed,
		FeedDBCol:   feeds,
	}
}
