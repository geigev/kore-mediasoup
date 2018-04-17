#ifndef MS_CHANNEL_UNIX_STREAM_SOCKET_HPP
#define MS_CHANNEL_UNIX_STREAM_SOCKET_HPP

#include "common.hpp"
#include "Channel/Request.hpp"
//#include "handles/UnixStreamSocket.hpp"

#include <json/json.h>
#include "uv_callback.h"

namespace Channel
{
	class UnixStreamSocket /* : public ::UnixStreamSocket */
	{
	public:
		class Listener
		{
		public:
			virtual void OnChannelRequest(Channel::UnixStreamSocket* channel, Channel::Request* request) = 0;
			virtual void OnChannelUnixStreamSocketRemotelyClosed(Channel::UnixStreamSocket* channel) = 0;
		virtual void mfuck() = 0;
		};

	public:
		explicit UnixStreamSocket(int fd);

	private:
		~UnixStreamSocket();

	public:
		uv_callback_t to_cpp;
		static void * on_to_cpp(uv_callback_t *callback,void*data);
		void SetListener(Listener* listener);
		//void getListener(
		void Send(Json::Value& msg);
		void SendLog(char* nsPayload, size_t nsPayloadLen);
		void SendBinary(const uint8_t* nsPayload, size_t nsPayloadLen);

		/* Pure virtual methods inherited from ::UnixStreamSocket. */
	public:
		void UserOnUnixStreamRead(char*k);// override;
		void UserOnUnixStreamSocketClosed(bool isClosedByPeer);//override;

	private:
		// Passed by argument.
		Listener* listener{ nullptr };
		// Others.
		Json::CharReader* jsonReader{ nullptr };
		Json::StreamWriter* jsonWriter{ nullptr };
		size_t msgStart{ 0 }; // Where the latest message starts.
		bool closed{ false };
	};
} // namespace Channel

#endif
