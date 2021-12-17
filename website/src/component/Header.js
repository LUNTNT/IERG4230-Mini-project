import logo from '../logo.png';
import React, {Component} from 'react'
import { Typography} from "@material-ui/core";
import '../App.css';

var headertextstyle = {
    fontsize : 50,
    fontFamily : "Noto Sans"
}

const ColoredLine = ({ color }) => (
    <hr
      style={{
        color,
        backgroundColor: color,
        height: 5
    
      }}
    />
);

class Header extends Component {

    render(){
        return (
            <header className="App-header">
                <a href='/home'> 
                    <img src={logo} alt="logo" height={150} width={150}/> 
                </a>
                <Typography style={headertextstyle}>
                    Smart Pet Feeder
                </Typography>
                <ColoredLine color="black" />
            </header>

        );

    };

}

export default Header;