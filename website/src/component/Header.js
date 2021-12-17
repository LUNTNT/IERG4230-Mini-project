import logo from '../logo.png';
import React, {Component} from 'react'
import { Typography} from "@material-ui/core";
import '../App.css';

var headertextstyle = {
    fontSize : 20,
}

const ColoredLine = ({ color }) => (
    <hr
      style={{
        color,
        backgroundColor: color,

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
<p></p>
                <ColoredLine color="black" />
            </header>
        );
    };
}

export default Header;