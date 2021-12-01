package Model

type Feed struct {

	ID      string `json:"id" bson:"id"`

	StartTime 	string `json:"start_time" bson:"start_time"`
	EndTime string `json:"end_time" bson:"end_time"`

	InitWeight float32 `json:"init_weight" bson:"init_weight"`
	FinalWeight float32 `json:"final_weight" bson:"final_weight"`


}


