import React, {Component} from 'react'
import { Button } from "@material-ui/core";
import '../App.css';
import axios from 'axios';
import Header from './Header';

var style = {
    textAlign:"center",
    flexDirection: "column"
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
                <Header />
                <p></p>
                    <Button variant="contained" onClick={this.handleClick}>
                        Feed
                    </Button>
                    <p></p>

                    <Button variant="contained" href="/stat" >
                        Statistic
                    </Button>
            </div>
        );
    };
}

export default Homepage;