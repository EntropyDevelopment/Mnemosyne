/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_MODE_BASE_INC
#	define ENTROPY_MNEMOSYNE_MODE_BASE_INC

#	include "EventHandler.hh"
#	include <Entropy/Theia/Scene.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			class Application;

			class ModeBase :
				public EventHandler
			{
				public:
					ModeBase(Application &);
					virtual ~ModeBase();
					virtual void makeCurrent();
					virtual DefaultedList<Theia::Scene>::iterator addScene();
					virtual void setScene(const DefaultedList<Theia::Scene>::iterator &);
				protected:
					virtual Theia::Scene &Current();
					virtual const Theia::Scene &Current() const;
					DefaultedList<Theia::Scene>::iterator getIterator() const;
				private:
					Application &_app;
					std::list<DefaultedList<Theia::Scene>::iterator> _scenes;
					DefaultedList<Theia::Scene>::iterator _current;
			};
		}
	}

#	include "Application.hh"

#endif
