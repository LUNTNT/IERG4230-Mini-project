package Model

type Feed struct {

	ID      string `json:"id" bson:"id"`

	StartTime 	string `json:"start_time" bson:"start_time"`
	EndTime string `json:"end_time" bson:"end_time"`

	OriginalWeight float32 `json:"original_weight" bson:"original_weight"`
	NewWeight float32 `json:"new_weight" bson:"new_weight"`


}


