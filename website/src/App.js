import React from "react";
import Homepage from "./component/Homepage";
import Feed from "./component/Feed";

import "./App.css";
import { Route, Routes, Switch } from 'react-router-dom'

import { Grid } from '@material-ui/core';

const App = () => {
  return (
    <Grid container direction="column">

    <div className="App">
        <Switch>
            <Route path="/" component={Homepage} />
            <Route path="/feed" component={Feed} />

        </Switch>
    </div>
    </Grid>
  );
}

export default App;