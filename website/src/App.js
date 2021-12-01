import logo from './logo.png';
import React, {Component} from 'react'
import { Typography, Link } from "@material-ui/core";
import './App.css';


var headertextstyle = {
    fontsize : 50,
    fontFamily : "Noto Sans"
}
class App extends Component {
    render() {
        return (
            <div className="App">
                <header className="App-header">
                    <img src={logo} alt="logo" height={150} width={150}/>
                    <Typography style={headertextstyle}>
                        Smart Pet Feeder
                    </Typography>
                </header>
            </div>
        )
    }

}

export default App;
