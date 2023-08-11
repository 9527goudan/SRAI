// Auto-generated. Do not edit!

// (in-package srv.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class speech_recognitionRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.WakenUp = null;
    }
    else {
      if (initObj.hasOwnProperty('WakenUp')) {
        this.WakenUp = initObj.WakenUp
      }
      else {
        this.WakenUp = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type speech_recognitionRequest
    // Serialize message field [WakenUp]
    bufferOffset = _serializer.int8(obj.WakenUp, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type speech_recognitionRequest
    let len;
    let data = new speech_recognitionRequest(null);
    // Deserialize message field [WakenUp]
    data.WakenUp = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'srv/speech_recognitionRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ef5adef9740917cec6e8de0887929470';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 WakenUp
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new speech_recognitionRequest(null);
    if (msg.WakenUp !== undefined) {
      resolved.WakenUp = msg.WakenUp;
    }
    else {
      resolved.WakenUp = 0
    }

    return resolved;
    }
};

class speech_recognitionResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.SpeechRecogition = null;
    }
    else {
      if (initObj.hasOwnProperty('SpeechRecogition')) {
        this.SpeechRecogition = initObj.SpeechRecogition
      }
      else {
        this.SpeechRecogition = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type speech_recognitionResponse
    // Serialize message field [SpeechRecogition]
    bufferOffset = _serializer.int8(obj.SpeechRecogition, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type speech_recognitionResponse
    let len;
    let data = new speech_recognitionResponse(null);
    // Deserialize message field [SpeechRecogition]
    data.SpeechRecogition = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'srv/speech_recognitionResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bdd8078035b634290176b31b40504008';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 SpeechRecogition
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new speech_recognitionResponse(null);
    if (msg.SpeechRecogition !== undefined) {
      resolved.SpeechRecogition = msg.SpeechRecogition;
    }
    else {
      resolved.SpeechRecogition = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: speech_recognitionRequest,
  Response: speech_recognitionResponse,
  md5sum() { return 'c05feedf1ccb8f1f38dacceac93906b6'; },
  datatype() { return 'srv/speech_recognition'; }
};
