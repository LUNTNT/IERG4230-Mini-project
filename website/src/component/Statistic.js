import React, {Component} from 'react'
import { Typography, Grid } from "@material-ui/core";
import Header from './Header';
import '../App.css';

var text = {
    fontSize : 20,
}
class Statistic extends Component {

    render(){
        return (
            <Grid>
                <div className='App'>
                    <Header/>

                    <Typography style={text}>
                        Feed History:
                    </Typography>
                    <p></p>
                    <div>
                        <iframe width="450" height="260" src="https://thingspeak.com/channels/1525712/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
                    </div>
                </div>
            </Grid>
                   
        );

    };

}

export default Statistic;