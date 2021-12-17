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
                    <p></p>
                    <div>
                        <iframe width="450" height="260" src="https://thingspeak.com/channels/1611327/charts/3?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line"></iframe>
                        <p></p>
                        <iframe width="450" height="260" src="https://thingspeak.com/channels/1611256/charts/2?bgcolor=%23ffffff&color=%23d62020&days=1&dynamic=true&results=60&title=Feed+Record&type=line"></iframe>
                    
                    </div>
                </div>
            </Grid>
                   
        );

    };

}

export default Statistic;