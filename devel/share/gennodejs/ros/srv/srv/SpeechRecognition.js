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

class SpeechRecognitionRequest {
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
        this.WakenUp = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SpeechRecognitionRequest
    // Serialize message field [WakenUp]
    bufferOffset = _serializer.bool(obj.WakenUp, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SpeechRecognitionRequest
    let len;
    let data = new SpeechRecognitionRequest(null);
    // Deserialize message field [WakenUp]
    data.WakenUp = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'srv/SpeechRecognitionRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6fced7e0db87647133531483e2687b25';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool WakenUp
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SpeechRecognitionRequest(null);
    if (msg.WakenUp !== undefined) {
      resolved.WakenUp = msg.WakenUp;
    }
    else {
      resolved.WakenUp = false
    }

    return resolved;
    }
};

class SpeechRecognitionResponse {
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
        this.SpeechRecogition = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SpeechRecognitionResponse
    // Serialize message field [SpeechRecogition]
    bufferOffset = _serializer.bool(obj.SpeechRecogition, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SpeechRecognitionResponse
    let len;
    let data = new SpeechRecognitionResponse(null);
    // Deserialize message field [SpeechRecogition]
    data.SpeechRecogition = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'srv/SpeechRecognitionResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '08f2232cd1fa1f37d6d3e69d7c20234a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool SpeechRecogition
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SpeechRecognitionResponse(null);
    if (msg.SpeechRecogition !== undefined) {
      resolved.SpeechRecogition = msg.SpeechRecogition;
    }
    else {
      resolved.SpeechRecogition = false
    }

    return resolved;
    }
};

module.exports = {
  Request: SpeechRecognitionRequest,
  Response: SpeechRecognitionResponse,
  md5sum() { return 'f0cb90399b5d115dbbf48f3fc50c1e7a'; },
  datatype() { return 'srv/SpeechRecognition'; }
};
