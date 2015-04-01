/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 */
'use strict';

var React = require('react-native');
var {
  AppRegistry,
  StyleSheet,
  Text,
  View,
  Image,
  TouchableHighlight,
} = React;

var HeaderView = require('./components/header');
var TokenView = require('./components/token');
var Lock = require('NativeModules').LockModule;

var LockReactNative = React.createClass({
  getInitialState: function() {
    return {
      logged: false,
    };
  },
  render: function() {
    if (this.state.logged) {
      return (
        <View style={styles.container}>
          <HeaderView/>
          <TokenView 
            style={styles.token}
            username={this.state.profile.username}
            email={this.state.profile.email}
            jwt={this.state.token.id_token}
          />
          <View style={styles.actionContainer}>
            <TouchableHighlight style={styles.actionButton} onPress={this._onLogout}>
              <Text style={styles.actionButtonText}>Logout</Text>
            </TouchableHighlight>
          </View>
        </View>
      );
    }
    return (
      <View style={styles.container}>
        <HeaderView/>
        <Text style={styles.message}>
          Please tap on 'Show Lock' to continue.
        </Text>
        <View style={styles.actionContainer}>
          <TouchableHighlight style={styles.actionButton} onPress={this._onShowLock}>
            <Text style={styles.actionButtonText}>Show Lock</Text>
          </TouchableHighlight>
        </View>
      </View>
    );
  },
  _onShowLock: function() {
    Lock.show((profile, token) => {
      this.setState({
        token: token,
        profile: profile,
        logged: true,
      });
    });
  },
  _onLogout: function() {
    this.setState({logged: false});
  },
});

var styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
    backgroundColor: '#F5FCFF',
  },
  token: {
    flex: 1,
  },
  actionContainer: {
    flex: 1,
    flexDirection: 'row',
    justifyContent: 'center',
    alignItems: 'flex-end',
    backgroundColor: '#F5FCFF',
  },
  actionButton: {
    width: 300,
    height: 50,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#16214D',
    borderRadius: 5,
    marginBottom: 20,
  },
  actionButtonText: {
    color: '#ffffff',
  },
  message: {
    fontFamily: 'HelveticaNeue-Thin',
    fontSize: 14,
    alignSelf: 'center',
  },
});

AppRegistry.registerComponent('LockReactNative', () => LockReactNative);
