set(GALAXY_EVENTS_SRC_DIR ${GALAXY_SRC_DIR}/Events) 

set(EVENT_SOURCES ${GALAXY_EVENTS_SRC_DIR}/Event.cpp
                  ${GALAXY_EVENTS_SRC_DIR}/Event.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/EventType.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/KeyboardEvent.cpp
                  ${GALAXY_EVENTS_SRC_DIR}/KeyboardEvent.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/KeyCodes.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/MouseCodes.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/MouseEvent.cpp
                  ${GALAXY_EVENTS_SRC_DIR}/MouseEvent.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/EventListeners/IEventListener.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/EventListeners/MouseEventListener.hpp
                  ${GALAXY_EVENTS_SRC_DIR}/EventListeners/MouseEventListener.cpp)