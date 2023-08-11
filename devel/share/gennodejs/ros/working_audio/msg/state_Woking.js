// Auto-generated. Do not edit!

// (in-package working_audio.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class state_Woking {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stateworking = null;
    }
    else {
      if (initObj.hasOwnProperty('stateworking')) {
        this.stateworking = initObj.stateworking
      }
      else {
        this.stateworking = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type state_Woking
    // Serialize message field [stateworking]
    bufferOffset = _serializer.int64(obj.stateworking, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type state_Woking
    let len;
    let data = new state_Woking(null);
    // Deserialize message field [stateworking]
    data.stateworking = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'working_audio/state_Woking';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dc665f7d3e15bf1394666a415605eaf6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 stateworking
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new state_Woking(null);
    if (msg.stateworking !== undefined) {
      resolved.stateworking = msg.stateworking;
    }
    else {
      resolved.stateworking = 0
    }

    return resolved;
    }
};

module.exports = state_Woking;
