﻿using System;

#if HAS_NEWTONSOFT_JSON
using Newtonsoft.Json.Linq;
#endif

namespace LookingGlass.Toolkit.Bridge
{
    /// <summary>
    /// <para>Describes a shared session connected to Looking Glass Bridge, synchronized via events.</para>
    /// <remarks>Note that multiple clients can connect to the same orchestration, receive the same events, and control the same state.</remarks>
    /// </summary>
    public class Orchestration
    {
        /// <summary>
        /// The unique identifier of this orchestration.
        /// </summary>
        public string Name { get; private set; }

        /// <summary>
        /// A UUID generated by Looking Glass Bridge, based on the <see cref="Name"/>.
        /// </summary>
        public string Token { get; private set; }

        private Orchestration(string name, string token)
        {
            this.Name = name;
            this.Token = token;
        }

        public static bool TryParse(string jsonString, out Orchestration orch)
        {
            try
            {
#if !HAS_NEWTONSOFT_JSON
            throw new NotSupportedException();
#else
                JObject json = JObject.Parse(jsonString);
                string name = json["orchestration"]?["value"]?.ToString();
                string token = json["payload"]?["value"]?.ToString();
                orch = new Orchestration(name, token);
                return true;
#endif
            }
            catch
            {
                orch = null;
                return false;
            }

        }

    }
}
