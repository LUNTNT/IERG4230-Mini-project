import React from "react";
import Homepage from "./component/Homepage";
import Statistic from "./component/Statistic";
import "./App.css";
import { Route, Switch, Link } from 'react-router-dom'

import { Grid } from '@material-ui/core';

const App = () => {
  return (
    <Grid container direction="column">
        <Switch>
            <Route path="/home" component={Homepage} />
            <Route path="/stat" component={Statistic} />
        </Switch>
    </Grid>
  );
}

export default App;