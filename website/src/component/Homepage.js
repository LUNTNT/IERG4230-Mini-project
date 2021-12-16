import logo from '../logo.png';
import React, {Component} from 'react'
import { Typography, Link, Button } from "@material-ui/core";
import '../App.css';
import axios from 'axios';


var headertextstyle = {
    fontsize : 50,
    fontFamily : "Noto Sans"
}


class Homepage extends Component {
    constructor() {
        super()

        this.handleClick = this.handleClick.bind(this)
    }

    handleClick() {
        axios.get('http://192.168.137.117/feed?time=5')
    }


    render() {
        return(
            <div className="App">
                <header className="App-header">
                    <img src={logo} alt="logo" height={150} width={150}/>
                    <Typography style={headertextstyle}>
                        Smart Pet Feeder
                    </Typography>

                </header>
                <p></p>
                     <Button variant="contained" onClick={this.handleClick}>
                        Feed
                    </Button>
                    <Button variant="contained" href="/stat" >
                        Statistic
                    </Button>
            </div>
        )
    }
}

export default Homepage;